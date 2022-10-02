#include <cstdlib>
#include <iostream>

#include <pistache/endpoint.h>

#include "../includes/utils/CommandQuery.hpp"
#include "../includes/config/Logger.hpp"
#include "../includes/routes/Marker.hpp"

using namespace Pistache;
using namespace Routes;

void run() {

  const std::string host = "localhost";
  const uint16_t port = 8088;
}

int main(int argc, char **argv) {

  // Config::Connect *query = new Config::Connect{};
  // query->query = "SELECT * FROM employers";
  // query->transac();
  // Utils::CommandQuery *query = new Utils::CommandQuery();
  // query->getter("SELECT * FROM emplers");

  // Http::listenAndServe<Marker>(Pistache::Address("*:8088"));

  return 0;
}
