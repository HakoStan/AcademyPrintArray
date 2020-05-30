#pragma once

#define VERIFY_AND_EXIT_PROGRAM(condition)		\
		{										\
			if(!condition)						\
			{									\
				std::cout << "invalid input";	\
				exit(1);						\
			}									\
		}