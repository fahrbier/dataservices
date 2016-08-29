<!-- #include file = "./services.inc" -->
<%
set ls = new LandmarkListService
ls.LandmarkListService("")

%>
<ul>
    <li><%= ls.data(0).getName() %><br/><%= ls.data(0).toJson() %></li>
    <li><%= ls.data(1).getName() %><br/><%= ls.data(1).toJson() %></li></ul>    