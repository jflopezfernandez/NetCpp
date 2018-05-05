
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iphlpapi.h>

#include <iostream>

#include <Poco/Poco.h>
#include <Poco/DateTime.h>
#include <Poco/HostEntry.h>
#include <Poco/IPAddress.h>
#include <Poco/LocalDateTime.h>
#include <Poco/Net.h>
#include <Poco/Net/DNS.h>
#include <Poco/Timestamp.h>

#include <boost/chrono.hpp>
#include <boost/math/tr1.hpp>
#include <boost/program_options.hpp>
#include <boost/random.hpp>
#include <boost/regex.hpp>
#include <boost/tokenizer.hpp>
#include <boost/token_functions.hpp>
#include <boost/token_iterator.hpp>


int main(int argc, char *argv[])
{
	const Poco::Net::HostEntry& entry = Poco::Net::DNS::hostByName("www.google.com");

	std::cout << "Canonical Name: " << entry.name() << "\n";

	//Poco::Net::IPAddress address;
	//Poco::Net::DNS googleDNS;
}
