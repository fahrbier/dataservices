if WScript.Arguments.Count = 0 then

    WScript.Echo "Missing parameters"

else
    file = ""
    className = WScript.Arguments(0)
    
    file = file & "class " & className & vbcrlf
    dim toJsonString()
    
    for a=1 to WScript.Arguments.Count-1 
        
        propertyName = lcase(WScript.Arguments(a))

        file = file & "    private " & propertyName & vbcrlf
        
        file = file & "    public function get" & ucaseFirst(propertyName) & vbcrlf
        file = file & "        get" & ucaseFirst(propertyName) & "=" & propertyName & vbcrlf
        file = file & "    end function" & vbcrlf
        
        file = file & "    public function set" & ucaseFirst(propertyName) & "(in" & ucaseFirst(propertyName) & ")" & vbcrlf
        file = file & "        " & propertyName & " = in" & ucaseFirst(propertyName) & vbcrlf
        file = file & "    end function" & vbcrlf & vbcrlf
        
        redim preserve toJsonString(a-1)
        toJsonString(a-1) = " """"" & propertyName & """"" : """""" & escape(" & propertyName & ") &" & " """""" " 
        
    next

    file = file &  "    public function toJson()"  & vbcrlf    
    file = file &  "        toJson = "" {" & join(toJsonString,",")  & "} "" " & vbcrlf
    file = file &  "    end function"  & vbcrlf
    
    file = file &  "    private function escape(inString)" & vbcrlf
    file = file &  "        if len(inString) > 0 then" & vbcrlf
    file = file &  "            escape = replace(inString ,"""""""",""\"""""") " & vbcrlf
    file = file &  "        end if" & vbcrlf
    file = file &  "    end function" & vbcrlf
    
    file = file &  "end class"
    
    WScript.Echo file
   
    Set objFSO=CreateObject("Scripting.FileSystemObject")
    Set objFile = objFSO.CreateTextFile("data" & ucaseFirst(className) &".inc",True)
    objFile.Write file & vbCrLf
    objFile.Close   
    
    
end if    


function ucaseFirst (s)
    ucaseFirst = ucase(left(s,1)) & mid(s,2)
end function


