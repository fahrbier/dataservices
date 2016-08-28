class person
    private id
    public function getId
        getId=id
    end function
    public function setId(inId)
        id = inId
    end function

    private surname
    public function getSurname
        getSurname=surname
    end function
    public function setSurname(inSurname)
        surname = inSurname
    end function

    private forename
    public function getForename
        getForename=forename
    end function
    public function setForename(inForename)
        forename = inForename
    end function

    private age
    public function getAge
        getAge=age
    end function
    public function setAge(inAge)
        age = inAge
    end function

    public function toJson()
        toJson = " { ""id"" : """ & id & """ , ""surname"" : """ & surname & """ , ""forename"" : """ & forename & """ , ""age"" : """ & age & """ } " 
    end function
end class
