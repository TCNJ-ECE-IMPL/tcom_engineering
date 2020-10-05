MSG = ["msg1", "msg2", "msg3"] #could do an enum instead also is a constant
EVENTS = ["event1", "event2", "event3"] #could do an enum instead also is a constant

class TCOM_Msg(object):
    def __init__(self, id) -> None:
        self.msgID = id
        self.lastSent = date.today()

    def UpdateDate(self) -> None:
        self.lastSent = date.today()

    def ReadDate(self) -> date:
        return self.lastSent

    def ReadID(self) -> string:
        return self.msgID

class TCOM_User_Events(object):

    def __init__(self) -> None:
        self.msgList = []
        self.hours = 0
        for x in MSG:
            self.msgList.push(TCOM_Msg(x))

    def SetHours(self, start_hour, end_hour) -> None:
        base = int('111111111111111111111111', 2) << start_hour # 24 bits
        mask = int('0111111111111111111111111', 2) >> end_hour
        self.hours = base & mask

    def ProcessEvents(self) -> None: # Can use Keys and maps to improve efficiency
        currentPriority = 0;
        send_msg = "0";

        for x in self.msgList
        #can be a switch case where the case is the msg
        if 1<2:
