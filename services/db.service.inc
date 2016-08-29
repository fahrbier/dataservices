class DbService
    
    private cString
    private cn
    private table
    private fields
    
    public hasError
    public errorMessage
    

    public function setConnectionString(inCstring)
        cString = inCstring
    end function
    
    public function setTable(inTable)
       table = inTable
    end function
    
    public function setFields(inFields)
        if not IsObject(inFields) then
            me.hasError = true
            me.errorMessage = me.errorMessage & "<li>Provided field names need to be a dictionary."
        else
            set fields = inFields
        end if    
    end function

    
    public function getData()
        c = getConnection()
        set rs = Server.CreateObject("ADODB.Recordset")
        sqlSelect = join (fields.keys, ",")        
        sql = "SELECT " & sqlSelect & " FROM " & table

        rs.open sql, cn
        getData = RS.GetRows()
        ''dumpResult(getData)
        
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