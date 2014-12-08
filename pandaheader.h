
#ifndef PANDA_HEADER_H

#define GET_DEV		0x0001 //client tells server to send it which devices are available
#define SET_DEV		0x0002 //server responds with available devices. can send whenever a new device is added without prompting
						   //also sent by rpi to tell server or its existence
#define GET_NAME	0x0003
#define SET_NAME	0x0004 //client tells server to set its name (uses signup Packet)
#define SET_OUT		0x0005 //client tells server which devices to forward too
#define PANDA_ACK	0x0006
#define PANDA_NACK	0x0007
#define AUDIO		0x0008
#define AVAILABLE	0x0009
#define SET_ID		0x000A

#define NUM_MAX_CLIENTS 10 //make sure to change padding below if these are changed
#define NUM_MAX_DEVICES 10
#define STR_BUFF_SZ		30

struct signupPacket
{
	uint32_t		address;
	char			name[STR_BUFF_SZ];
	char			pack[2];
};
struct selectPacket
{
	uint8_t			cl_array_idx;
	char			selected[NUM_MAX_DEVICES];
	char			pack[1];
};
struct devPacket
{
	char			devices[NUM_MAX_CLIENTS][STR_BUFF_SZ];
};
struct pandaPacketData
{
	char		cl_array_idx; //what client is currently sending to the server. gotten from server responce. 
	char		pack[3];
	uint8_t		data[1000];
};//keep size under 1500

#define PANDA_HEADER_H
#endif