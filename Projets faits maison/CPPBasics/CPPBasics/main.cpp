#include <iostream>


struct Log
{
	enum Level
	{
		Info, Warn, Error
	};
	static int m_LogLevel;

	void setLevel(int level)
	{
		m_LogLevel = level;
	}

	Log()
	{
		m_LogLevel = 0;
	}

	void info(const char* message) const
	{
		if(m_LogLevel <= Info)
			std::cout << "[Information] : " << message << std::endl;
	}
	void error(const char* message) const
	{
		if (m_LogLevel <= Error)
			std::cout << "[Error] : " << message << std::endl;
	}
	void warn(const char* message) const
	{
		if (m_LogLevel <= Warn)
			std::cout << "[Warning] : " << message << std::endl;
	}
};

int Log::m_LogLevel;

//int main()
//{
//	Log log;
//	Log log2;
//
//	log.setLevel(log.Warn);
//
//	log.error("This is an error...!?");
//	log.warn("This is a warning...!?");
//	log.info("This is an info...!?");
//
//	log.setLevel(log.Info);
//
//	log2.error("This is an error...!?");
//	log2.warn("This is a warning...!?");
//	log2.info("This is an info...!?");
//}