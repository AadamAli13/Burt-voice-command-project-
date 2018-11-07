#include "JsonParser.h"

using namespace std;
vector<string> JsonParser::parseJSON(std::string result){
	vector<string> command;
	Json::Reader reader;
	Json::Value obj;
	reader.parse(result, obj);
	string subject = obj["entities"]["message_subject"][0]["value"].asString();
	string intent = obj["entities"]["on_off"][0]["value"].asString();
	command.push_back(subject);
	// won't always be "on_off"
	command.push_back(intent);
	if (obj["entities"]["duration"] != "Null"){
		string duration = obj["entities"]["duration"][0]["normalized"]["value"].asString(); 
		string unit = obj["entities"]["duration"][0]["normalized"]["unit"].asString(); 
		command.push_back(duration);
		command.push_back(unit);
	}
	
	return command;
}
