#include "channel.hpp"

int	f_stoi( std::string numb ) {
	int		ret;

	std::stringstream var(numb);
	var >> ret;
	return ret;
}

int main() {
	std::cout << f_stoi(var) + 1 << std::endl;
}