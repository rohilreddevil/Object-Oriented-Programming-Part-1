

#ifndef AMA_ERROR_STATE_H_
#define AMA_ERROR_STATE_H_

#include <iostream>

namespace AMA {

	class ErrorState {
		char *MESSAGE;
	public:
		explicit ErrorState(const char *errorMessage = nullptr);
		ErrorState(const ErrorState &) = delete;
		virtual ~ErrorState();//deallocator
		ErrorState &operator=(const ErrorState &) = delete;
		void clear();
		bool isClear() const;
		void message(const char *str);
		const char *message() const;
	};
	std::ostream &operator<<(std::ostream &os, const ErrorState &er);

}  
#endif  // AMA_ERROR_STATE_H_
