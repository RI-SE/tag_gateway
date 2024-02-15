#include "crow.h"

#define CROW_STATIC_DIRECTORY "/var/www/tag_gateway/static"

int main()
{
    crow::SimpleApp app;

    // enable ssl
    app.ssl_file("/etc/tag_gateway/cert/server.cert", "/etc/tag_gateway/cert/server.key");

    CROW_WEBSOCKET_ROUTE(app, "/ws")
      .onopen([&](crow::websocket::connection& conn) {
          CROW_LOG_INFO << "new websocket connection from " << conn.get_remote_ip();
      })
      .onclose([&](crow::websocket::connection& conn, const std::string& reason) {
          CROW_LOG_INFO << "websocket connection closed: " << reason;
      })
      .onmessage([&](crow::websocket::connection& /*conn*/, const std::string& data, bool is_binary) {
        CROW_LOG_INFO << "received " << (is_binary ? "binary" : "text") << " message: " << data;
      });
    CROW_ROUTE(app, "/")
    ([](const crow::request&, crow::response& res) {
        res.set_static_file_info_unsafe(CROW_STATIC_DIRECTORY "/index.html");
        res.end();
    });

    app.port(8443)
      .multithreaded()
      .run();
}