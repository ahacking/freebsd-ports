--- rexxcurl.c.orig	Tue Dec  5 16:30:55 2006
+++ rexxcurl.c	Tue Dec  5 16:31:14 2006
@@ -323,7 +323,7 @@
    { "RANGE"           ,CURLOPT_RANGE           ,RXCURLOPT_STRING      },
    { "REFERER"         ,CURLOPT_REFERER         ,RXCURLOPT_STRING      },
    { "RESUMEFROM"      ,CURLOPT_RESUME_FROM     ,RXCURLOPT_LONGLONG    },
-#if LIBCURL_VERSION_NUM >= 0x070d00
+#if LIBCURL_VERSION_NUM >= 0x070d00 && LIBCURL_VERSION_NUM < 0x071000
    { "SOURCEPOSTQUOTE" ,CURLOPT_SOURCE_POSTQUOTE,RXCURLOPT_LIST        },
    { "SOURCEPREQUOTE"  ,CURLOPT_SOURCE_PREQUOTE ,RXCURLOPT_LIST        },
    { "SOURCEQUOTE"     ,CURLOPT_SOURCE_QUOTE    ,RXCURLOPT_LIST        },
