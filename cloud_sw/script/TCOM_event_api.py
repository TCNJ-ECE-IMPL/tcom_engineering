from datetime import timedelta
import csv
import math

class TCOM_Msg(object):
    def __init__(self, id, msg) -> None:
        self.msgId = id
        self.msgValue = msg
        self.lastSent = datetime.now() #chane to date w/ time down to seconds

    def UpdateDate(self) -> None:
        self.lastSent = datetime.now()

    def ReadDate(self) -> datetime:
        return self.lastSent

    def ReadID(self) -> int:
        return self.msgId

    def ReadMsg(self) -> string:
        return self.msgValue

class TCOM_Event(object):
    def __init__(self, id, event, tau) -> None:
        self.eventId = id
        self.eventType = event
        self.tau = tau
        self.lastOccured = datetime.now() #chane to date w/ time down to seconds
        self.eventValue = 1
        self.logCount = 0
        self.hasOccuredOnce = false

    def UpdateDate(self, date) -> None:
        self.lastSent = date #In format of datetime

    def UpdateValue(self, x) -> None:
        self.eventValue = x

    def UpdateLog(self, x) -> None:
        self.logCount = x

    def ReadDate(self) -> datetime:
        return self.lastSent

    def ReadValue(self) -> Float:
        return self.Tau

    def ReadValue(self) -> Int:
        return self.eventValue

    def ReadLog(self) -> string:
        return self.logCount

    def ReadID(self) -> string:
        return self.eventId

    def ReadEvent(self) -> string:
        return self.eventType

class TCOM_User_Events(object):

    def __init__(self) -> None: #TODO: The data shouldnt change so it should be changed to be more repeatable
        with open('test.csv', newline='') as csvfile: #Reads CSV File lines
            spamreader = csv.reader(csvfile, delimiter=' ', quotechar='|')
            read_msg = true; #indicates if reading the top row with the messages
            event_counter = 0
            for row in spamreader:
                if read_msg:
                    msg_counter = 0
                    for x in row[1:]:
                        self.msgList.push(TCOM_Msg.new(msg_counter, x)) #stores all messages
                        msg_counter = msg_counter + 1
                    read_msg = false
                else:
                    self.eventList.push(TCOM_Event.new(event_counter, row[0],row[1])) #Stores all events
                    self.eventWeights.push(row[2:]) #Stores all the event and message weights
                    event_counter = event_counter + 1

    def SetHours(self, start_hour, end_hour) -> None:
        if: start_hour < end_hour:
            base = int('0111111111111111111111111', 2) << start_hour # 24 bits
            mask = int('0111111111111111111111111', 2) >> (23 - end_hour)
            self.hours = base & mask
        else:
            base = int('0111111111111111111111111', 2) << end_hour # 24 bits
            mask = int('0111111111111111111111111', 2) >> (23 - start_hour)
            self.hours = ~(base & mask)

    def ProcessEvents(self) -> string:
        current_priority = 0
        send_msg = "NULL"
        current_time = datetime.now()

        for x in self.msgList:
            temp_priority = (current_time-x.ReadDate()).days
            for y in self.eventList:
                exp_value = exp(-(current_time.days-y.ReadDate().days)/y.ReadTau()) #e^(-delta_t/tau)
                weight = self.eventWeights[x.ReadID()][y.ReadID()]
                temp_priority = temp_priority + (y.ReadValue() * exp_value  * weight) #TODO: Should we have negative priorities or only poisitive ones?
            if temp_priority > current_priority:
                send_msg = x.ReadMsg();

        return send_msg
