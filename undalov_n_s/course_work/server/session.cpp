#include "session.h"

Session::Session(Client * client, int id)
{
  this->client = client;
  this->id = id;
}
