class PersonService

    public meta
    public data

    public default function PersonService(parameter)
        
        set p = new Person
        p.setSurname("Lersch")
        p.setForename("Holger")
        
        
        set me.data = p
    end function

end class