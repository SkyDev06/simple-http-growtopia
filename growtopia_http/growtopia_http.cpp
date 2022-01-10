#include <iostream>
#include "httplib.h"

using namespace std;
using namespace httplib;

int main() {
	//HTTP
	Server grow;

	//IP & PORT
	string ip_server = "127.0.0.1";
	int port_server = 80;

	//Default
	grow.Get("/", [](const Request &req, Response &res) {
		string ip = req.remote_addr;
		res.set_content("Hello From HTTP C++", "text/plain");
		cout << "Connection From " + ip + "\n";
	});

	//Growtopia
	grow.Post("/growtopia/server_data.php", [](const Request &req, Response &res) {
		//server_data.php Data
		string ip_gt = "127.0.0.1";
		int port_gt = 17091;
		string data_gt = "server|" + ip_gt + "\nport|" + to_string(port_gt) + "\ntype|1\n#maint|Mainetrance message (Not used for now) -- Adip\n\nbeta_server|127.0.0.1\nbeta_port|17091\n\nbeta_type|1\nmeta|localhost\nRTENDMARKERBS1001";

		//Request
		string ip = req.remote_addr;
		res.set_content(data_gt, "Content-Type': 'text/html");
		cout << "Connection From " + ip + "\n";
	});

	//Create HTTP
	grow.listen(ip_server.c_str(), port_server);
}