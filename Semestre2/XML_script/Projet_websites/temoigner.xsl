<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="2.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">


<xsl:template match="/">
<html>
    <head>
        <title>ma biblio</title>
        <link rel="stylesheet" href="html.css"/>
        <link rel="stylesheet" href="style.css"/> 
    </head>

    <body>
        <h3>Le site pour répertorier toutes les manières de témoigner de sa foi</h3>
        <br /> <br />
        <ul>
            <xsl:for-each select="bibliotheque/methodes">
                
                <xsl:sort select="methode/titre" order="ascending"/>
                <h5><xsl:value-of select="methode/titre"/></h5>
                <table border="1" width="800" style="background-color:#FFFFCC">
                    <tr>
                        <td class="image"><img src="{couverture/@scr}"/></td>
                        <td>
                        <p>
                            <span>Auteur(s) :</span>
                            <br />
                                <ul>
                                    <xsl:for-each select="methode/auteurs/auteur">
                                        <xsl:value-of select="."></xsl:value-of>
                                    </xsl:for-each>
                                </ul>
                            <br />
                            <span>Nombre de personnes adéquat :</span> <xsl:value-of select="nbPersonne"/>
                        </p>
                        </td>
                    </tr>
                    <tr>
                        <td colspan="2">Description : <br></br><xsl:value-of select="methode/description"/></td>
                    </tr>
                </table>
            </xsl:for-each>
        </ul>
    </body>
</html>
</xsl:template>






</xsl:stylesheet>