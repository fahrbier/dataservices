<!-- #include file = "./services.inc" -->
<%
set param = Server.CreateObject("Scripting.Dictionary")
param.add "idCategory", Request.QueryString("idCategory")

set nwsl = new NewsListService
nwsl.NewsListService(param)
Response.AddHeader "Content-Type","application/json"
response.write nwsl.jsonArray 
%>   