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
        fields.add "latitude",""
        fields.add "longitude",""
        db.setFields(fields)
        
        lmData = db.getData()
 
        for l=0 to ubound(lmData,2)
            set p = new Landmark
            p.setId(lmData(db.mapField("id"),l))
            p.setName(lmData(db.mapField("name"),l))
            p.setLatitude(lmData(db.mapField("latitude"),l))
            p.setLongitude(lmData(db.mapField("longitude"),l))
            
            redim preserve data(l)
            set data(l) = p
            set p = nothing
            
        next       
        


    end function

end class