<!-- #include file = "./services.inc" -->
<%
set ls = new LandmarkListService
ls.LandmarkListService("")

set ps = new PersonService
ps.PersonService("")


%>

<%= ps.data.Forename() %> - <%= ps.data.Surname() %>
<%= ps.data.toJson() %>

<ul>
    <li><%= ls.data(0).Name() %><br/><%= ls.data(0).toJson() %></li>
    <li><%= ls.data(1).Name() %><br/><%= ls.data(1).toJson() %></li>
</ul>

<%= ls.jsonArray %>    
