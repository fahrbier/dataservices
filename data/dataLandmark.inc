''+-------------------------------------
''+- Auto-Generated 2016-9-3
''+-------------------------------------

class Landmark

    ''+-------------------------------------
    ''+- id, string
    ''+-------------------------------------
    private stringId
    public property Get Id()
        Id = stringId
    end property
    public property Let Id (inId)
        stringId = inId
    end property
    ''+-------------------------------------
    ''+- name, real
    ''+-------------------------------------
    private realName
    public property Get Name()
        Name = realName
    end property
    public property Let Name (inName)
        realName = inName
    end property
    ''+-------------------------------------
    ''+- longitude, real
    ''+-------------------------------------
    private realLongitude
    public property Get Longitude()
        Longitude = realLongitude
    end property
    public property Let Longitude (inLongitude)
        realLongitude = inLongitude
    end property
    ''+-------------------------------------
    ''+- latitude, integer
    ''+-------------------------------------
    private integerLatitude
    public property Get Latitude()
        Latitude = integerLatitude
    end property
    public property Let Latitude (inLatitude)
        integerLatitude = inLatitude
    end property

    public function toJson()
        toJson = "{" _ 
                & """id"" : """ & escape(stringId) & """, " _ 
                & """name"" : """ & escape(realName) & """, " _ 
                & """longitude"" : """ & escape(realLongitude) & """, " _ 
                & """latitude"" : """ & escape(integerLatitude) & """" _ 
                & "}"
    end function
    
    private function escape(inString)
        if len(inString) > 0 then 
            escape = replace(inString,"""","\""")
        else
            escape = inString
        end if    
    end function 

end class