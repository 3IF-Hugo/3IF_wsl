<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:output method="html"/>
  <xsl:template match="/">
    <html>
      <head>
        <title>XSLT Excercises</title>
      </head>
       <body bgcolor="beige">
        <H1>Company Information for Infoteria</H1>
        <H2>Employee Listing</H2>
        <table border="1" align="center">
          <tr>
            <th>Name</th>
            <th>Position</th>
            <th>E-mail</th>
          </tr>
          <!-- <xsl:for-each-group select="//Employee" group-by="distinct-values(//Email[//Employee[substring-before(substring-after(Email,'@'),'.')]])">
            <xsl:for-each select="current-group()">
              <tr>
                <td><xsl:value-of select="FirstName"/><xsl:text> </xsl:text><xsl:value-of select="LastName"/></td>
                <td><xsl:value-of select="Position"/></td>
                <td><xsl:value-of select="Email"/></td>
            </tr>  
            </xsl:for-each>
          </xsl:for-each-group> -->

          <!-- Question 5 groupe par adresse mail -->
          <!-- <xsl:for-each select="//Employee">
          <xsl:sort select="substring-after(Email, '@')"/>
          <xsl:sort select="LastName" order="descending"/>
          Ne marche pas... <xsl:sort select="//Employee[substring-after(Email,'@')]" order="ascending"/>
            <tr>
                <td><xsl:value-of select="FirstName"/><xsl:text> </xsl:text><xsl:value-of select="LastName"/></td>
                <td><xsl:value-of select="Position"/></td>
                <td><xsl:value-of select="Email"/></td>
            </tr>
          </xsl:for-each> -->

          <!-- Question 6 : zébré -->
          <xsl:for-each select="//Employee">
						
						<xsl:element name="tr">
						<xsl:attribute name="bgcolor">
							<xsl:if test="position() mod 2=1">
							FFFFFF
							</xsl:if>
							<xsl:if test="position() mod 2=0">
							beige
							</xsl:if>
						</xsl:attribute>
						
							<td>
								<xsl:value-of select="FirstName"/>
								<xsl:text> </xsl:text>
								<xsl:value-of select="LastName"/>
							</td>
							<td>
								<xsl:value-of select="Position"/>
							</td>
							<td>
								<xsl:value-of select="Email"/>
							</td>
						</xsl:element>
					</xsl:for-each>



          <!-- <xsl:for-each select="//Employee">
          <xsl:if test="Age &lt; 30">
            <tr>
              <td><xsl:value-of select="FirstName"/><xsl:text> </xsl:text><xsl:value-of select="LastName"/></td>
              <td><xsl:value-of select="Position"/></td>
              <td><xsl:value-of select="Email"/></td>
          </tr>  
          </xsl:if> -->

          <!-- <xsl:for-each select="//Employee">
          <xsl:sort select="LastName" order="ascending"/>
            <tr>
                <td><xsl:value-of select="FirstName"/><xsl:text> </xsl:text><xsl:value-of select="LastName"/></td>
                <td><xsl:value-of select="Position"/></td>
                <td><xsl:value-of select="Email"/></td>
            </tr>
          </xsl:for-each> -->

        <!-- </xsl:for-each> -->
          <!-- <! <xsl:apply-templates/> -->
        </table>
        <!-- <p align="center">Total Employees: <xsl:value-of select="count(//Employee[Age &lt; 30])" /></p> -->
        <p align="center">Total Employees: <xsl:value-of select="count(//Employee)" /></p>
      </body>
    </html>
  </xsl:template>
  
  <!-- <xsl:template match="Employee">
      <tr>
        <td><xsl:value-of select="FirstName"/> <xsl:value-of select="LastName"/></td>
        <td><xsl:value-of select="Position"/></td>
        <td><xsl:value-of select="Email"/></td>
    </tr>      
  </xsl:template> -->

 <!--  -->

</xsl:stylesheet>
