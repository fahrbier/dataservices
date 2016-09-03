''+-------------------------------------
''+- Auto-Generated 2016-9-3
''+-------------------------------------

class Person

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
    ''+- forename, string
    ''+-------------------------------------
    private stringForename
    public property Get Forename()
        Forename = stringForename
    end property
    public property Let Forename (inForename)
        stringForename = inForename
    end property
    ''+-------------------------------------
    ''+- surname, string
    ''+-------------------------------------
    private stringSurname
    public property Get Surname()
        Surname = stringSurname
    end property
    public property Let Surname (inSurname)
        stringSurname = inSurname
    end property
    ''+-------------------------------------
    ''+- age, integer
    ''+-------------------------------------
    private integerAge
    public property Get Age()
        Age = integerAge
    end property
    public property Let Age (inAge)
        integerAge = inAge
    end property

    public function toJson()
        toJson = "{" _ 
                & """id"" : """ & escape(stringId) & """, " _ 
                & """forename"" : """ & escape(stringForename) & """, " _ 
                & """surname"" : """ & escape(stringSurname) & """, " _ 
                & """age"" : """ & escape(integerAge) & """" _ 
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