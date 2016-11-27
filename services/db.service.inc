class DbService
    
    private cString
    private cn
    private table
    private fields
    
    private joinTables()
    private joinExpressions()
    
    private countJoinTables 
    private countJoinExpressions 
    
    private filter()
    private countFilter
    
    private sql
    
    private countResults
    
    public hasError
    public errorMessage
    

    public function setConnectionString(inCstring)
        cString = inCstring
    end function
    
    public function setTable(inTable)
       table = inTable
    end function

    public function addJoinTable(inTable, inExpression)

       redim preserve joinTables(countJoinTables)
       joinTables(countJoinTables)           = inTable
       countJoinTables      = countJoinTables + 1
       
       redim preserve joinExpressions(countJoinTables)
       joinExpressions(countJoinExpressions) = inExpression
       countJoinExpressions = countJoinExpressions + 1       

    end function    
    
    public function addFilter(inField, inFilter)
       
       redim preserve filter(countFilter)
       filter(countFilter) = inField & " " & inFilter
       countFilter         = countFilter + 1

    end function       
    
    public function setFields(inFields)
        if not IsObject(inFields) then
            me.hasError = true
            me.errorMessage = me.errorMessage & "<li>Provided field names need to be a dictionary."
        else
            set fields = inFields
        end if    
    end function
    
    public function getCountResults()
       getCountResults = countResults
    end function    

    
    public function getData()
        c = getConnection()
        set rs = Server.CreateObject("ADODB.Recordset")
        sqlSelect = join (fields.keys, ",")        
        
        
        sqlWhereJoin = ""
        sqlFrom      = ""
        if countJoinTables > 0 then
            sqlFrom = table
            sqlWhereJoin = " WHERE "
            for jc = 0 to countJoinTables -1                     
                sqlFrom      = sqlFrom & ", " & joinTables(jc)
                
                if jc>0 then
                    sqlWhereJoin = sqlWhereJoin & " AND "
                end if
                sqlWhereJoin = sqlWhereJoin & joinExpressions(jc)
            next    
        
        else 
            sqlFrom = table
        end if
        
        sqlWhereFilter = " "
        if countFilter > 0 then
            if countJoinTables = 0 then 
               sqlWhereFilter = " WHERE "
            end if
            
            for fc = 0 to countFilter -1                     
                if (fc > 0 or countJoinTables > 0) then
                    sqlWhereFilter = sqlWhereFilter & " AND "
                end if
                sqlWhereFilter = sqlWhereFilter & filter(fc)
            next              
        
        end if
        
        sql = "SELECT " & sqlSelect & " FROM " & sqlFrom & sqlWhereJoin & sqlWhereFilter
        sqlCount = "SELECT count( * ) FROM " & sqlFrom & sqlWhereJoin & sqlWhereFilter
        
        ''response.write sql
        ''response.write "<hr>"
        ''response.write sqlCount
        ''response.end

        rs.open sqlCount, cn
        countData = rs.GetRows()
        rs.close
        countResults = countData(0,0)
        
        if countResults > 0 then 
            rs.open sql, cn
            getData = rs.GetRows()
            ''dumpResult(getData)
            rs.close
        end if    
        
        c = shutdownConnection()
    end function
    
    public function mapField(nameField)
        if fields.exists(nameField) then
            fieldArray = fields.keys
            for mf = 0 to ubound(fieldArray) 
                if  fieldArray(mf) = nameField then mapField = mf
            next
        else
            mapField = 0
            me.hasError = true
            me.errorMessage = me.errorMessage & "<li>Provided field name wasn't requested."
        end if    
    end function 
    
    private function dumpResult(rsGetRows)

        tmpCol = ubound(rsGetRows,1)
        tmpRow = ubound(rsGetRows,2)
        response.write "<blockquote><h3>Result:</h3><table border=""1"">"
        for tmpDebugOutR = 0 to tmpRow
            response.write "<tr>"
            for tmpDebugOutC = 0 to tmpCol
                 response.write "<td><tt>" & rsGetRows(tmpDebugOutC,tmpDebugOutR) & "</tt></td>"
            next
            response.write "</tr>"
        next
        response.write "</table></blockquote>"        

    end function
    
    
    private function getConnection()
        set cn = Server.CreateObject("ADODB.Connection")
        cn.open cString
    end function   

    private function shutdownConnection()
        cn.close
        set cn = nothing
    end function     
  
  


end class