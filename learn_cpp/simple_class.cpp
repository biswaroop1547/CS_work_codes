#include<iostream>



class Log{
	
	public:
		enum Level: int {
			
			LevelError = 0, LevelWarning, LevelInfo
		};

	private:
		Level m_LogLevel = LevelInfo;
	

	public:

		void setLogLevel(Level level){
			m_LogLevel = level;
		}


		void Error(const char *msg){

			if(m_LogLevel >= LevelError){
				std::cout << "[ERROR]: " << msg << std::endl;
			}
		}
		

		void Warn(const char *msg){

			if(m_LogLevel >= LevelWarning){
				std::cout << "[WARNING]: " << msg << std::endl;
			}
		}	
		

		void Info(const char *msg){

			if(m_LogLevel >= LevelInfo){
				std::cout << "[INFO]: " << msg << std::endl;
			}
		}		
	

};

int main(){

	Log log;
	
	log.setLogLevel(Log::LevelInfo);

	log.Warn("Hello world");
	log.Error("Hello world");
	log.Info("Hello world");

	std::cin.get();
}
