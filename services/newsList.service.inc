class NewsListService

    public meta
    public data()
    public jsonArray

    public default function NewsListService(parameter)

        if not IsObject(parameter) then
            me.hasError = true
            me.errorMessage = me.errorMessage & "<li>Provided parameters names needs to be provided in a dictionary, even an empty one."
            exit function
        end if 
    
        set conf = new Configuration
        set db = new DbService
        set fields = Server.CreateObject("Scripting.Dictionary")
        
        db.setConnectionString(conf.dbConnectionString)
        db.setTable("view_news")
        
        if parameter.Exists("idCategory") then
            db.addJoinTable "n_news_2_category",  "view_news.id = n_news_2_category.id_news"
            db.addFilter "n_news_2_category.id_category", "=" & parameter.item("idCategory")
        end if
         
        fields.add "id",""
        fields.add "dateNews",""
        fields.add "headline",""
        fields.add "idSupplier",""
        fields.add "dateCreated",""
        
        db.setFields(fields)
        
        nmData = db.getData()
        dim tmpJson()
        if db.getCountResults() > 0 then
            for l=0 to ubound(nmData,2)
                set nm = new News
                nm.Id          = nmData(db.mapField("id"),l)
                nm.DateNews    = nmData(db.mapField("dateNews"),l)
                nm.Headline    = nmData(db.mapField("headline"),l)
                nm.IdSupplier  = nmData(db.mapField("idSupplier"),l)
                nm.DateCreated = nmData(db.mapField("dateCreated"),l)
          
                redim preserve data(l)
                redim preserve tmpJson(l)
                
                set data(l) = nm
                tmpJson(l) = nm.toJson()
                set nm = nothing
            next       
        end if        
        
        me.jsonArray = " {""meta"":{ ""amount"":"""& db.getCountResults() &""" },""data"" : [" & join(tmpJson,",") & "]}"


    end function

end class