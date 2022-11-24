#include <cstdlib>
#include <iostream>

#include <pistache/endpoint.h>

#include "../includes/utils/Queries.hpp"
#include "../includes/config/Logger.hpp"
#include "../includes/routes/Marker.hpp"

void run() {

  const std::string host = "localhost";
  const uint16_t port = 8088;
}

int main(int argc, char **argv) {


  Utils::Queries query{};
  query.from("users").method("select");
  auto body = query.exec();

  std::cout << body.size();

  // Router::Marker *marker = new Router::Marker();

  // delete marker;

  return 0;
}
