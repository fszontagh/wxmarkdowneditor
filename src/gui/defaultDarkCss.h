#ifndef DEFAULT_CSS_H
#define DEFAULT_CSS_H

#include <wx/string.h>

inline const wxString defaultCssDark = "body { font-family: -apple-system, BlinkMacSystemFont, \"Segoe UI\", \"Roboto\", \"Oxygen\", \"Ubuntu\", \"Cantarell\", \"Fira Sans\", \"Droid Sans\", \"Helvetica Neue\", sans-serif; line-height: 1.6; margin: 0; padding: 20px; background-color: #121212; color: #e0e0e0; } a { color: #4a90e2; text-decoration: none; } a:hover { text-decoration: underline; } h1, h2, h3, h4, h5, h6 { margin: 0.5em 0; font-weight: bold; color: #e0e0e0; } h1 { font-size: 2em; border-bottom: 2px solid #444; padding-bottom: 0.3em; } h2 { font-size: 1.5em; border-bottom: 2px solid #444; padding-bottom: 0.3em; } h3 { font-size: 1.2em; } h4, h5, h6 { font-size: 1em; } pre, code { font-family: 'Courier New', Courier, monospace; font-size: 0.9em; } pre { background-color: #2d2d2d; border: 1px solid #444; border-radius: 3px; padding: 16px; overflow-x: auto; color: #f8f8f2; } code { padding: 2px 4px; background-color: #333; border-radius: 3px; font-size: 0.9em; color: #f8f8f2; } ul, ol { margin: 1em 0; padding-left: 20px; } li { margin: 0.5em 0; } ul { list-style-type: disc; } ol { list-style-type: decimal; } blockquote { margin: 1em 0; padding: 0.5em 1em; border-left: 4px solid #444; background-color: #2d2d2d; color: #a0a0a0; } a { color: #4a90e2; } a:visited { color: #4a90e2; } a:hover { text-decoration: underline; } table { width: 100%; margin: 1em 0; border-collapse: collapse; } th, td { border: 1px solid #444; padding: 8px; text-align: left; color: #e0e0e0; } th { background-color: #2d2d2d; font-weight: bold; } tr:nth-child(odd) { background-color: #2d2d2d; } tr:hover { background-color: #444; } img { max-width: 100%; height: auto; border: none; box-shadow: none; } strong { font-weight: bold; } em { font-style: italic; } del { text-decoration: line-through; } .bg-gray-light { background-color: #2d2d2d; } .text-muted { color: #a0a0a0; } .text-danger { color: #d73a49; }";

#endif // DEFAULT_CSS_H
