class person
    private name
    public function getName
        return name
    end function

    public function setName(inName)
         name = inName
    end function

    private vorname
    public function getVorname
        return vorname
    end function

    public function setVorname(inVorname)
         vorname = inVorname
    end function

    public function toJson()
        toJson = " { ""name"" : """ & name & """ , ""vorname"" : """ & vorname & """ } " 
    end function
end class
