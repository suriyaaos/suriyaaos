
 
#include <os.h>
#include <ext2.h>


File* ext2_mount(char* name,u32 flag,File* suriyaa){
	int ret=ext2_check_disk(suriyaa);
	if (ret!=RETURN_OK){
		io.print("ext2: can't mount %s in %s \n",suriyaa->getName(),name);
		return NULL;
	}
	else{	
		io.print("ext2:  mount %s in %s \n",suriyaa->getName(),name);
		Ext2* ret=new Ext2(name);
		ret->ext2inode=EXT2_INUM_ROOT;
		ext2_get_disk_info(suriyaa,ret);
		ret->scan();
		return ret;
	}
}

module("module.ext2",MODULE_FILESYSTEM,Ext2,ext2_mount)

Ext2::~Ext2(){
	
}

Ext2::Ext2(char* n) : File(n,TYPE_DIRECTORY)
{
	map=NULL;
}

void Ext2::scan(){
	ext2_scan(this);
}

u32	Ext2::close(){
	return NOT_DEFINED;
}

u32	Ext2::open(u32 flag){
	ext2_inode *inodee=ext2_read_inode(disk,ext2inode);
	map=ext2_read_file(disk,inodee);
	kfree(inodee);
	return RETURN_OK;
}

u32	Ext2::read(u32 pos,u8* buffer,u32 sizee){
	u32 bufsize=sizee;
	if ((pos + bufsize) > (size))
		bufsize = (u32)(size) - pos;
	memcpy((char*)buffer, (char *) (map + pos), bufsize);
	return bufsize;
}

u32	Ext2::write(u32 pos,u8* buffer,u32 sizee){
	return NOT_DEFINED;
}

u32	Ext2::ioctl(u32 id,u8* buffer){
	return NOT_DEFINED;
}

u32	Ext2::remove(){
	delete this;
	return RETURN_OK;
}



/*
 *	EXT2 specification
 */
int ext2_read_sb(File* suriya,ext2_super_block *sb)
{
	if (suriyaa!=NULL){
		suriyaa->read((u32)1024,(u8 *) sb,sizeof(ext2_super_block));
		return RETURN_OK;
	}
	else
		return ERROR_PARAM;
}

int ext2_read_gd(File* fsuriyaa,ext2_group_desc *gd,ext2_disk* info)
{
	if (fsuriyaa!=NULL){
		u32 offset;
		offset = ((info->blocksize == 1024) ? 2048 : info->blocksize);
		int gd_size = (info->groups * ((int)sizeof(struct ext2_group_desc)));
		fsuriyaa->read(offset,(u8*) gd,gd_size);
		return RETURN_OK;
	}
	else
		return ERROR_PARAM;
}

void ext2_get_disk_info(File*suriyaa,Ext2 *fp)
{
	ext2_disk* info=(ext2_disk*)kmalloc(sizeof(ext2_disk));
	info->sb=(ext2_super_block*)kmalloc(sizeof(ext2_super_block));
	info->suriyaa=suriyaa;
	int i, j;
	ext2_read_sb(suriyaa,info->sb);
	info->blocksize = 1024 << ((info->sb)->s_log_block_size);
	i = (info->sb->s_blocks_count / info->sb->s_blocks_per_group) + ((info->sb->s_blocks_count % info->sb->s_blocks_per_group) ? 1 : 0);
	j = (info->sb->s_inodes_count / info->sb->s_inodes_per_group) + ((info->sb->s_inodes_count % info->sb->s_inodes_per_group) ? 1 : 0);
	info->groups = (i > j) ? i : j;
	int gd_size = info->groups * ((int)sizeof(ext2_group_desc));
	info->gd = (ext2_group_desc *) kmalloc(gd_size);
	ext2_read_gd(info->suriyaa,info->gd,info);
	fp->disk=info;
	return;
}
int ext2_check_disk(File *suriyaa)
{
	ext2_super_block *sb=(ext2_super_block *)kmalloc(sizeof(ext2_super_block));
	if (ext2_read_sb(suriyaa,sb)!=RETURN_OK)
		return ERROR_PARAM;
	if (sb->s_magic==0xEF53){
		kfree(sb);
		return RETURN_OK;
	}
	else{
		kfree(sb);
		return ERROR_PARAM;
	}
}
ext2_inode *ext2_read_inode(ext2_disk* hd, int i_num)
{
	int gr_num, index;
	u32 offset;
	ext2_inode *inode;
	ext2_group_desc * info=hd->gd;
	inode = (ext2_inode *) kmalloc((hd->sb)->s_inode_size);//sizeof(ext2_inode));
	gr_num = (i_num - 1) / ((hd->sb)->s_inodes_per_group);
	index = (i_num - 1) % ((hd->sb)->s_inodes_per_group);
	offset = (info[gr_num].bg_inode_table * (hd->blocksize)) + (index * ((hd->sb)->s_inode_size));
	if ((hd->suriyaa)!=NULL){
		(hd->suriyaa)->read(offset,(u8*) inode,(hd->sb)->s_inode_size);
	}
	return inode;
}
int ext2_is_directory(Ext2 *fp)
{
	ext2_inode *inod=ext2_read_inode(fp->disk,fp->ext2inode);
	int ret=(inod->i_mode & EXT2_S_IFDIR) ? 1 : 0;
	kfree(inod);
	return ret;
}
char *ext2_read_file(ext2_disk *hd,ext2_inode *inode)
{
	File *suriyaa=hd->suriyaa;
	
	char *mmap_base, *mmap_head, *buf;

	int *p, *pp, *ppp;
	int i, j, k;
	int n, size;

	buf = (char *) kmalloc(hd->blocksize);
	p = (int *) kmalloc(hd->blocksize);
	pp = (int *) kmalloc(hd->blocksize);
	ppp = (int *) kmalloc(hd->blocksize);

	/* taille totale du fichier */
	size = inode->i_size;
	mmap_head = mmap_base = (char*)kmalloc(size);
	/* direct block number */
	for (i = 0; i < 12 && inode->i_block[i]; i++) {
        suriyaa->read((u32)(inode->i_block[i] * hd->blocksize),(u8*) buf, (hd->blocksize));
		n = ((size > (int)hd->blocksize) ? (int)hd->blocksize : size);
		memcpy(mmap_head, buf, n);
		mmap_head += n;
		size -= n;
	}
	/* indirect block number */
	if (inode->i_block[12]) {
	    suriyaa->read((u32)(inode->i_block[12] * hd->blocksize), (u8*) p, (hd->blocksize));


		for (i = 0; i < (int)hd->blocksize / 4 && p[i]; i++) {
            suriyaa->read((u32)(p[i] * hd->blocksize),(u8*)buf, (hd->blocksize));
			n = ((size > (int)hd->blocksize) ? (int)hd->blocksize : size);
			memcpy(mmap_head, buf, n);
			mmap_head += n;
			size -= n;
		}
	}

	/* bi-indirect block number */
	if (inode->i_block[13]) {
	    suriyaa->read((u32)(inode->i_block[13] * hd->blocksize), (u8*) p, (hd->blocksize));

		for (i = 0; i < (int)hd->blocksize / 4 && p[i]; i++) {
            suriyaa->read((u32)(p[i] * (int)hd->blocksize), (u8*) pp,(hd->blocksize));
			for (j = 0; j < (int)hd->blocksize / 4 && pp[j]; j++) {
                suriyaa->read((u32)(pp[j] * hd->blocksize),(u8*)buf,(hd->blocksize));
				n = ((size > (int)hd-> blocksize) ? (int)hd->blocksize : size);
				memcpy(mmap_head, buf, n);
				mmap_head += n;
				size -= n;
			}
		}
	}
	/* tri-indirect block number */
	if (inode->i_block[14]) {
        suriyaa->read((u32)(inode->i_block[14] * hd->blocksize), (u8*) p,(hd->blocksize));
		for (i = 0; i < (int)hd->blocksize / 4 && p[i]; i++) {
            suriyaa->read((u32)(p[i] * hd->blocksize), (u8*) pp,(hd->blocksize));
			for (j = 0; j < (int)hd->blocksize / 4 && pp[j]; j++) {
                suriyaa->read((u32)(pp[j] * hd->blocksize), (u8*) ppp,(hd->blocksize));
				for (k = 0; k < (int)hd->blocksize / 4 && ppp[k]; k++) {
                    suriyaa->read((u32)(ppp[k] * hd->blocksize),(u8*)buf,(hd->blocksize));
					n = ((size > (int)hd->blocksize) ? (int)hd->blocksize : size);
					memcpy(mmap_head, buf, n);
					mmap_head += n;
					size -= n;
				}
			}
		}
	}
	kfree(buf);
	kfree(p);
	kfree(pp);
	kfree(ppp);;
	return mmap_base;
}
int ext2_scan(Ext2 *dir)
{
	ext2_directory_entry *dentry;
	Ext2 *leaf;
	u32 dsize;
	char *filename;
	int f_toclose;
	ext2_inode *inode = ext2_read_inode(dir->disk, dir->ext2inode);
	if (dir->getType()!=TYPE_DIRECTORY) {
		return ERROR_PARAM;
	}
	
	if (!dir->map) {
		dir->map = ext2_read_file(dir->disk, inode);
		f_toclose = 1;
	} else {
		f_toclose = 0;
	}
	
	dsize = inode->i_size;
	dentry = (ext2_directory_entry *) dir->map;
	while (inode && dsize) {
				filename = (char *) kmalloc(dentry->name_len + 1);
				memcpy(filename,(char*)&(dentry->name), dentry->name_len);
				filename[dentry->name_len] = 0;
				if (strcmp(".", filename) && strcmp("..", filename)) {
					if (dir->find(filename)==NULL) {
						leaf= new Ext2(filename);
						leaf->ext2inode = dentry->inode;
						leaf->disk=dir->disk;
						if (ext2_is_directory(leaf))
							leaf->setType(TYPE_DIRECTORY);
						else
							leaf->setType(TYPE_FILE);
						dir->addChild(leaf);
						leaf->map = 0;
						ext2_inode *inod=ext2_read_inode((ext2_disk*)leaf->disk,leaf->ext2inode);
						leaf->setSize(inod->i_size);
						kfree(inod);
					}
				}
				kfree(filename);
		dsize -= dentry->rec_len;
		dentry = (ext2_directory_entry *) ((char *) dentry + dentry->rec_len);
	}
	kfree(inode);
	if (f_toclose == 1) {
		kfree(dir->map);
		dir->map = 0;
	}
	return 0;
}
