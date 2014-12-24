#include "../basics_all.h"

IWTextCommunicatorStream IWTextCommunicator::GetOutStream()
{
	return IWTextCommunicatorStream(this);
}
