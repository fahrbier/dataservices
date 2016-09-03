class LandmarkListService

    public meta
    public data()
    public jsonArray

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
        dim tmpJson()
        for l=0 to ubound(lmData,2)
            set lm = new Landmark
            lm.Id        = lmData(db.mapField("id"),l)
            lm.Name      = lmData(db.mapField("name"),l)
            lm.Latitude  = lmData(db.mapField("latitude"),l)
            lm.Longitude = lmData(db.mapField("longitude"),l)
            
            redim preserve data(l)
            redim preserve tmpJson(l)
            
            set data(l) = lm
            tmpJson(l) = lm.toJson()
            set lm = nothing
        
        next       
        
        me.jsonArray = " {""data"" : [" & join(tmpJson,",") & "]}"


    end function

end class