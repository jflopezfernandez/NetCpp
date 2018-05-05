
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iphlpapi.h>

#include <iostream>
#include <iomanip>
#include <string>

#include <Poco/Poco.h>
#include <Poco/DateTime.h>
#include <Poco/HostEntry.h>
#include <Poco/IPAddress.h>
#include <Poco/LocalDateTime.h>
#include <Poco/Net.h>
#include <Poco/Net/DNS.h>
#include <Poco/Net/Socket.h>
#include <Poco/Net/SocketAddress.h>
#include <Poco/Net/StreamSocket.h>
#include <Poco/Timestamp.h>

#include <boost/chrono.hpp>
#include <boost/math/tr1.hpp>
#include <boost/optional.hpp>
#include <boost/program_options.hpp>
#include <boost/random.hpp>
#include <boost/regex.hpp>
#include <boost/tokenizer.hpp>
#include <boost/token_functions.hpp>
#include <boost/token_iterator.hpp>


int main(int argc, char *argv[])
{
	boost::optional<std::string> serverAddress = boost::make_optional<std::string>("");

	try {
		boost::program_options::options_description generic("Generic options");
		generic.add_options()
			("help,h", "Display help dialog")
			("version,v", "Display program version")
			("server-address,sa", boost::program_options::value<std::string>(), "Server address to ping");
	
		// TODO: Parse command line
		// TODO: Read in input
		// TODO: Do something with the input

	} catch (std::exception& e) {
		std::cerr << "[Error]: " << e.what() << "\n";
	}

	const Poco::Net::HostEntry& entry = Poco::Net::DNS::hostByName("www.google.com");
	std::cout << "Canonical Name: " << entry.name() << "\n";

	const Poco::Net::HostEntry::AliasList& aliases = entry.aliases();
	Poco::Net::HostEntry::AliasList::const_iterator aliasIterator = aliases.begin();

	std::cout << "Aliases: \n";
	for (; aliasIterator != aliases.end(); ++aliasIterator) {
		std::cout << "\t" << *aliasIterator << "\n";
	}

	const Poco::Net::HostEntry::AddressList& addrs = entry.addresses();
	Poco::Net::HostEntry::AddressList::const_iterator addressIterator = addrs.begin();

	std::cout << "Addresses: \n";
	for (; addressIterator != addrs.end(); ++addressIterator) {
		std::cout << "\t" << addressIterator->toString() << "\n";
	}

	return EXIT_SUCCESS;
}
