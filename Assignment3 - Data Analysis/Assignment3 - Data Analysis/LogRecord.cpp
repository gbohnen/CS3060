//
//  LogRecord.cpp
//  tconley-hw3
//
//  Created by Thomas Alan Conley on 10/6/16.
//  Copyright © 2016 Thomas Alan Conley. All rights reserved.
//

#include "LogRecord.hpp"
#include <sstream>
#include "LogFieldTime.hpp"
#include "LogFieldAddr.hpp"
#include "LogFieldPort.h"
#include "LogFieldInterval.h"
#include "LogFieldCount.hpp"
#include "LogFieldBool.h"
#include "LogFieldSetStr.h"
#include <typeinfo>

LogRecord::LogRecord(const std::string &line)
{
    // here are the descriptions of the fields from
    // conn.log... use this as a guide for initializing
    // the object from the string that is passed in
    
    //#fields	ts	uid	id.orig_h	id.orig_p	id.resp_h	id.resp_p	proto	service	duration	orig_bytes	resp_bytes	conn_state	local_orig	local_resp	missed_bytes	history	orig_pkts	orig_ip_bytes	resp_pkts	resp_ip_bytes	tunnel_parents	orig_cc	resp_cc	sensorname
    //#types	time	string	addr	port	addr	port	enum	string	interval	count	count	string	bool	bool	count	string	count	count	count	count	set[string]	string	string	string
    
    std::istringstream iss(line);
    std::string field;
    
    // time
    iss >> field;
    fields.push_back(new LogFieldTime(field));
    
    // uid
    iss >> field;
    fields.push_back(new LogField(field));
    
    // orig_h
    iss >> field;
    fields.push_back(new LogFieldAddr(field));

	// orig_p
	iss >> field;
	fields.push_back(new LogFieldPort(field));

	// resp_h
	iss >> field;
	fields.push_back(new LogFieldAddr(field));

	// resp_p
	iss >> field;
	fields.push_back(new LogFieldPort(field));

	// proto
	iss >> field;


	// service
	iss >> field;
	fields.push_back(new LogField(field));

	// duration
	iss >> field;
	fields.push_back(new LogFieldInterval(field));

	// orig_bytes
	iss >> field;
	fields.push_back(new LogFieldCount(field));

	// resp_bytes
	iss >> field;
	fields.push_back(new LogFieldCount(field));

	// conn_state
	iss >> field;
	fields.push_back(new LogField(field));

	// local_orig
	iss >> field;
	fields.push_back(new LogFieldBool(field));

	// local_resp
	iss >> field;
	fields.push_back(new LogFieldBool(field));

	// missed_bytes
	iss >> field;
	fields.push_back(new LogFieldCount(field));

	// history
	iss >> field;
	fields.push_back(new LogField(field));

	// orig_pkts
	iss >> field;
	fields.push_back(new LogFieldCount(field));

	// orig_ip_bytes
	iss >> field;
	fields.push_back(new LogFieldCount(field));

	// resp_pkts
	iss >> field;
	fields.push_back(new LogFieldCount(field));

	// resp isp_ bytes
	iss >> field;
	fields.push_back(new LogFieldCount(field));

	// tunnel_parents
	iss >> field;
	fields.push_back(new LogFieldSetStr(field));

	// orig_cc
	iss >> field;
	fields.push_back(new LogField(field));

	// resp_cc
	iss >> field;
	fields.push_back(new LogField(field));

	// sensorname
	iss >> field;
	fields.push_back(new LogField(field));
    
    //
    // ... continue loading the rest of the fields
    //
}

LogRecord::~LogRecord()
{
    // I'm responsible for deleting fields
    //                   -- LogRecord
    for(const LogField *lf : fields)
    {
        delete lf;
    }
}
void LogRecord::Add(const LogField* lf)
{
    fields.push_back(lf);
}
const std::string LogRecord::toString() const
{
    std::ostringstream oss;
    for(const LogField *lf : fields)
    {
        oss << lf->toString() << '\x09';
    }
    return oss.str();
}
