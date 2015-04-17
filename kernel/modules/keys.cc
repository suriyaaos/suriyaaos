
#include <os.h>
#include <keys.h>

#include <api/suriyaa/ioctl.h>

extern char* kbdmap;

File* keys_mknod(char* name,u32 flag,File* suriyaa){
	Keyboard* cons=new Keyboard(name);
	return cons;
}

module("module.keyboard",MODULE_DEVICE,Keyboard,keys_mknod)

Keyboard::~Keyboard(){
	
}

Keyboard::Keyboard(char* n) : Device(n)
{

}

void Keyboard::scan(){

}

u32	Keyboard::close(){
	return RETURN_OK;
}

u32	Keyboard::open(u32 flag){
	return RETURN_OK;
}

u32	Keyboard::read(u32 pos,u8* buffer,u32 sizee){
	return NOT_DEFINED;
}

u32	Keyboard::write(u32 pos,u8* buffer,u32 sizee){
	return NOT_DEFINED;
}

u32	Keyboard::ioctl(u32 id,u8* buffer){
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
			
		case API_KEYBOARD_SET_TABLE:
			memcpy(scantable,(char*)buffer,TABLE_KEYBOARD_SIZE);
			kbdmap=scantable;
			ret=TABLE_KEYBOARD_SIZE;
			break;
	
		default:
			ret=NOT_DEFINED;
	}
	return ret;
}

u32	Keyboard::remove(){
	delete this;
	return RETURN_OK;
}
