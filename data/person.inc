<%
class Person
    private name
    private vorname
    
    public function getName()
         getName = name
    end function

    public function setName(inName)
        name = inName
    end function   

    public function getVorname()
         getVorname = vorname
    end function

    public function setVorname(inName)
        vorname = inName
    end function     

    public function toJson()
    
    end function
    
    public function toString()
        toString = "<h1>Person</h1><ul>" _
                 & "<li>name:" & name _
                 & "<li>vorname:" & vorname _
                 & "</ul>"
    end function    
end class
%>