#include "BusinessUser.h"

void BusinessUser::SendMessage(User* user, Message* message)
{
	user->recieveMessage(message);
}
