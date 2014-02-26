(load (string-append laml-dir "laml.scm"))
(laml-style "xml-in-laml/schemedoc-index/schemedoc-index")
(manual-index
 (manual-index-front-matters
  (manual-index-title "QRE API Manual Index")
  'browser-type "one-step"     ; one-step or two-steps
  'left-frame-width "250px"
  'top-frame-height "200px"
  'initial-manual-frame "first-manual-contribution"
  'source-destination-delta ""
  'scheme-report "none"       ; none, include, merge
  )
;; Indexing region
(manual-index-contributions
  (manual-index-contribution
   'informative-name "layout3func.manlsp"
   'path "layout3func.manlsp"
  )  (manual-index-contribution
   'informative-name "mathfunc.manlsp"
   'path "mathfunc.manlsp"
  )  (manual-index-contribution
   'informative-name "tools1func.manlsp"
   'path "tools1func.manlsp"
  )  (manual-index-contribution
   'informative-name "routingfunc.manlsp"
   'path "routingfunc.manlsp"
  )  (manual-index-contribution
   'informative-name "lookupfunc.manlsp"
   'path "lookupfunc.manlsp"
  )  (manual-index-contribution
   'informative-name "menu2func.manlsp"
   'path "menu2func.manlsp"
  )  (manual-index-contribution
   'informative-name "fillerfunctions.manlsp"
   'path "fillerfunctions.manlsp"
  )  (manual-index-contribution
   'informative-name "menu4func.manlsp"
   'path "menu4func.manlsp"
  )  (manual-index-contribution
   'informative-name "layout1func.manlsp"
   'path "layout1func.manlsp"
  )  (manual-index-contribution
   'informative-name "layout2func.manlsp"
   'path "layout2func.manlsp"
  )))
