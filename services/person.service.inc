<%
class PersonService

    public meta
    public data

    public default function PersonService(mpid)
        metaData = ""
        
        set p = new Person
        p.setName("Lersch")
        p.setVorname("Holger")
        
        
        set me.data = p
    end function

end class
%>