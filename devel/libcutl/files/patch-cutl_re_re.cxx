Use regex from C++11 instead of boost/tr1's version (the latter is gone as of
boost 1.65).
--- cutl/re/re.cxx.orig	2017-07-14 14:59:43 UTC
+++ cutl/re/re.cxx
@@ -9,7 +9,7 @@
 #ifndef LIBCUTL_EXTERNAL_BOOST
 #  include <cutl/details/boost/tr1/regex.hpp>
 #else
-#  include <boost/tr1/regex.hpp>
+#  include <regex>
 #endif
 
 using namespace std;
@@ -40,17 +40,17 @@ namespace cutl
     struct basic_regex<C>::impl
     {
       typedef basic_string<C> string_type;
-      typedef tr1::basic_regex<C> regex_type;
+      typedef std::basic_regex<C> regex_type;
       typedef typename regex_type::flag_type flag_type;
 
       impl () {}
       impl (regex_type const& r): r (r) {}
       impl (string_type const& s, bool icase)
       {
-        flag_type f (tr1::regex_constants::ECMAScript);
+        flag_type f (std::regex_constants::ECMAScript);
 
         if (icase)
-          f |= tr1::regex_constants::icase;
+          f |= std::regex_constants::icase;
 
         r.assign (s, f);
       }
@@ -118,15 +118,15 @@ namespace cutl
           impl_ = s == 0 ? new impl : new impl (*s, icase);
         else
         {
-          impl::flag_type f (tr1::regex_constants::ECMAScript);
+          impl::flag_type f (std::regex_constants::ECMAScript);
 
           if (icase)
-            f |= tr1::regex_constants::icase;
+            f |= std::regex_constants::icase;
 
           impl_->r.assign (*s, f);
         }
       }
-      catch (tr1::regex_error const& e)
+      catch (std::regex_error const& e)
       {
         throw basic_format<char> (s == 0 ? "" : *s, e.what ());
       }
@@ -146,15 +146,15 @@ namespace cutl
           impl_ = s == 0 ? new impl : new impl (*s, icase);
         else
         {
-          impl::flag_type f (tr1::regex_constants::ECMAScript);
+          impl::flag_type f (std::regex_constants::ECMAScript);
 
           if (icase)
-            f |= tr1::regex_constants::icase;
+            f |= std::regex_constants::icase;
 
           impl_->r.assign (*s, f);
         }
       }
-      catch (tr1::regex_error const& e)
+      catch (std::regex_error const& e)
       {
         throw basic_format<wchar_t> (s == 0 ? L"" : *s, e.what ());
       }
@@ -166,28 +166,28 @@ namespace cutl
     bool basic_regex<char>::
     match (string_type const& s) const
     {
-      return tr1::regex_match (s, impl_->r);
+      return std::regex_match (s, impl_->r);
     }
 
     template <>
     bool basic_regex<wchar_t>::
     match (string_type const& s) const
     {
-      return tr1::regex_match (s, impl_->r);
+      return std::regex_match (s, impl_->r);
     }
 
     template <>
     bool basic_regex<char>::
     search (string_type const& s) const
     {
-      return tr1::regex_search (s, impl_->r);
+      return std::regex_search (s, impl_->r);
     }
 
     template <>
     bool basic_regex<wchar_t>::
     search (string_type const& s) const
     {
-      return tr1::regex_search (s, impl_->r);
+      return std::regex_search (s, impl_->r);
     }
 
     template <>
@@ -196,13 +196,13 @@ namespace cutl
              string_type const& sub,
              bool first_only) const
     {
-      tr1::regex_constants::match_flag_type f (
-        tr1::regex_constants::format_default);
+      std::regex_constants::match_flag_type f (
+        std::regex_constants::format_default);
 
       if (first_only)
-        f |= tr1::regex_constants::format_first_only;
+        f |= std::regex_constants::format_first_only;
 
-      return tr1::regex_replace (s, impl_->r, sub, f);
+      return std::regex_replace (s, impl_->r, sub, f);
     }
 
     template <>
@@ -211,13 +211,13 @@ namespace cutl
              string_type const& sub,
              bool first_only) const
     {
-      tr1::regex_constants::match_flag_type f (
-        tr1::regex_constants::format_default);
+      std::regex_constants::match_flag_type f (
+        std::regex_constants::format_default);
 
       if (first_only)
-        f |= tr1::regex_constants::format_first_only;
+        f |= std::regex_constants::format_first_only;
 
-      return tr1::regex_replace (s, impl_->r, sub, f);
+      return std::regex_replace (s, impl_->r, sub, f);
     }
   }
 }
