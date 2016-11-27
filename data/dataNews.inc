''+-------------------------------------
''+- Auto-Generated 2016-11-25
''+-------------------------------------

class News

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
    ''+- dateNews, date
    ''+-------------------------------------
    private dateDateNews
    public property Get DateNews()
        DateNews = dateDateNews
    end property
    public property Let DateNews (inDateNews)
        dateDateNews = inDateNews
    end property
    ''+-------------------------------------
    ''+- headline, string
    ''+-------------------------------------
    private stringHeadline
    public property Get Headline()
        Headline = stringHeadline
    end property
    public property Let Headline (inHeadline)
        stringHeadline = inHeadline
    end property
    ''+-------------------------------------
    ''+- idSupplier, string
    ''+-------------------------------------
    private stringIdSupplier
    public property Get IdSupplier()
        IdSupplier = stringIdSupplier
    end property
    public property Let IdSupplier (inIdSupplier)
        stringIdSupplier = inIdSupplier
    end property
    ''+-------------------------------------
    ''+- dateCreated, date
    ''+-------------------------------------
    private dateDateCreated
    public property Get DateCreated()
        DateCreated = dateDateCreated
    end property
    public property Let DateCreated (inDateCreated)
        dateDateCreated = inDateCreated
    end property

    public function toJson()
        toJson = "{" _ 
                & """id"" : """ & escape(stringId) & """, " _ 
                & """dateNews"" : """ & escape(dateDateNews) & """, " _ 
                & """headline"" : """ & escape(stringHeadline) & """, " _ 
                & """idSupplier"" : """ & escape(stringIdSupplier) & """, " _ 
                & """dateCreated"" : """ & escape(dateDateCreated) & """" _ 
                & "}"
    end function
    
    private function escape(inString)
        if len(inString) > 0 then 
            escape = replace(replace(replace(inString,"""","\"""),VBCRLF," "),VBLF," ")
        else
            escape = inString
        end if    
    end function 

end class