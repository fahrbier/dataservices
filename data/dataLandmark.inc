class landmark
    private id
    public function getId
        getId=id
    end function
    public function setId(inId)
        id = inId
    end function

    private name
    public function getName
        getName=name
    end function
    public function setName(inName)
        name = inName
    end function

    private latitude
    public function getLatitude
        getLatitude=latitude
    end function
    public function setLatitude(inLatitude)
        latitude = inLatitude
    end function

    private longitude
    public function getLongitude
        getLongitude=longitude
    end function
    public function setLongitude(inLongitude)
        longitude = inLongitude
    end function

    public function toJson()
        toJson = " { ""id"" : """ & id & """ , ""name"" : """ & name & """ , ""latitude"" : """ & latitude & """ , ""longitude"" : """ & longitude & """ } " 
    end function
end class
