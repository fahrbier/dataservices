class news
    private id
    public function getId
        getId=id
    end function
    public function setId(inId)
        id = inId
    end function

    private headline
    public function getHeadline
        getHeadline=headline
    end function
    public function setHeadline(inHeadline)
        headline = inHeadline
    end function

    private body
    public function getBody
        getBody=body
    end function
    public function setBody(inBody)
        body = inBody
    end function

    public function toJson()
        toJson = " { ""id"" : """ & id & """ , ""headline"" : """ & headline & """ , ""body"" : """ & body & """ } " 
    end function
end class
