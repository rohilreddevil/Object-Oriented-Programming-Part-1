#ifndef AMA_ErrorState_h
#define AMA_ErrorState_h

#include <iostream>

namespace AMA {

	class ErrorState {

		char*MESSAGE;
	public:
		explicit ErrorState(const char* errorMessage = nullptr);
		ErrorState(const ErrorState&) = delete; //copy constructor
		ErrorState& operator=(const ErrorState&) = delete; //deleted assignment operator
		virtual ~ErrorState(); //deallocator
		void clear();
		bool isClear() const;
		void message(const char*str);
		const char* message() const;

	};
	std::ostream& operator<<(std::ostream&os, const ErrorState&er);




}


#endif // !AMA_ErrorState_h

