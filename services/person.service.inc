class PersonService

    public meta
    public data

    public default function PersonService(parameter)
        
        set p = new Person
        p.Surname = "Lersch"
        p.Forename = "Holger"
        
        
        set me.data = p
    end function

end class