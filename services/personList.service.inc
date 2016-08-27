<%
class PersonListService

    public meta
    public data()

    public default function PersonListService(input)
        metaData = ""
        
        set p = new Person
        p.setName("Lersch")
        p.setVorname("Holger")
        
        redim preserve data(0)
        set me.data(0) = p
        
        set p = new Person
        p.setName("Schmidt")
        p.setVorname("Erik")
        
        redim preserve data(1)
        set me.data(1) = p


    end function

end class
%>