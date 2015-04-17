
#include <os.h>
#include <null.h>

#include <api/suriyaa/ioctl.h>

File* null_mknod(char* name,u32 flag,File* suriyaa){
	Null* cons=new Null(name);
	return cons;
}

module("module.null",MODULE_DEVICE,Null,null_mknod)

Null::~Null(){
	
}

Null::Null(char* n) : Device(n)
{

}

void Null::scan(){

}

u32	Null::close(){
	return RETURN_OK;
}

u32	Null::open(u32 flag){
	return RETURN_OK;
}

u32	Null::read(u32 pos,u8* buffer,u32 size){
	memset((char*)buffer,0,size);
	return size;
}

u32	Null::write(u32 pos,u8* buffer,u32 size){
	return size;
}

u32	Null::ioctl(u32 id,u8* buffer){
	u32 ret=0;
	switch (id){
		case SURIYAA_GET_TYPE:
			ret=SURIYAA_TYPE_TTY;
			break;
			
		case SURIYAA_GET_STATE:
			ret=SURIYAA_STATE_OK;
			break;
			
		case SURIYAA_GET_FORMAT:
			ret=SURIYAA_FORMAT_CHAR;
			break;
	
		default:
			ret=NOT_DEFINED;
	}
	return ret;
}

u32	Null::remove(){
	delete this;
	return RETURN_OK;
}
