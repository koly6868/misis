#ifndef SESSION_H
#define SESSION_H

#include "client.h"

struct Session
{
public:
  Session(Client* client, int id);

public:
  Client* client;
  int id;
};
#endif // !SESSION_H
