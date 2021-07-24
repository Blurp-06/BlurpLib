#ifndef BSL_LOG
#define BSL_LOG
#define ENUM_STRING(ENUM) #ENUM
#include <fstream>

namespace BSL
{
	/// <summary>
	/// The severity of the log message.
	/// </summary>

	enum class Severity
	{
		Warning,
		Error,
		Info
	};


	/// <summary>
	/// This class will handle writing to the log file.
	/// </summary>
	class Logger
	{
	private:
		std::ofstream file;
		const char* filename;

	public:
		// Opens file.
		Logger(const char* _filename) : filename(_filename) 
		{
			file.open(filename, std::ios_base::app);
		};

		/// <summary>
		/// Function will write a message to the log with the time, severity and message.
		/// </summary>
		/// <param name="severity">Pass a value from the severity struct, use the ENUM_STRING macro.</param>
		/// <param name="message">The message to write.</param>
		void log(const char* severity, const char* message)
		{
			file
				<< '['
				<< __DATE__
				<< ' '
				<< __TIME__
				<< " | "
				<< severity
				<< ']'
				<< ' '
				<< message
				<< std::endl;
		}
	};
}

#endif // !LOG