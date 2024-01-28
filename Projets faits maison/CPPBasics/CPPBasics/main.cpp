#include <iostream>

int Ask();

class Log
{
public:
	int LogLevelError = 2;
	int LogLevelWarning = 1;
	int LogLevelInfo = 0;

private:
	int m_LogLevel = 0;

public:
	void setLevel(int level)
	{
		m_LogLevel = level;
	}


	void info(const char* message)
	{
		if(m_LogLevel <= LogLevelInfo)
			std::cout << "[Information] : " << message << std::endl;
	}
	void error(const char* message)
	{
		if (m_LogLevel <= LogLevelError)
			std::cout << "[Error] : " << message << std::endl;
	}
	void warn(const char* message)
	{
		if (m_LogLevel <= LogLevelWarning)
			std::cout << "[Warning] : " << message << std::endl;
	}
};


int main()
{
	Log log;
	log.setLevel(log.LogLevelWarning);
	log.error("This is an error...!?");
	log.warn("This is a warning...!?");
	log.info("This is an info...!?");
}