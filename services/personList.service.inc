class PersonListService

    public meta
    public data()

    public default function PersonListService(parameter)
        
        set p = new Person
        p.setSurname("Lersch")
        p.setForename("Holger")
        
        redim preserve data(0)
        set me.data(0) = p
        
        set p = new Person
        p.setSurname("Schmidt")
        p.setForename("Erik")
        
        redim preserve data(1)
        set me.data(1) = p


    end function

end class