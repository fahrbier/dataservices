class LandmarkListService

    public meta
    public data()

    public default function LandmarkListService(parameter)
        
        set conf = new Configuration
        set db = new DbService
        set fields = Server.CreateObject("Scripting.Dictionary")
        
        db.setConnectionString(conf.dbConnectionString)
        db.setTable("view_landmark")
         
        fields.add "id",""
        fields.add "name",""
        db.setFields(fields)
        
        db.getData()
              
        
        
        set p = new Landmark
        p.setSurname("Lersch")
        p.setForename("Holger")
        
        redim preserve data(0)
        set me.data(0) = p
        
        set p = new Landmark
        p.setSurname("Schmidt")
        p.setForename("Erik")
        
        redim preserve data(1)
        set me.data(1) = p


    end function

end class