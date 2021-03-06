//            Copyright (c) Glyn Matthews 2011.
// Copyright 2012 Google, Inc.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once
#ifndef ___RSS_INC__
#define ___RSS_INC__


#include <string>
#include <vector>
#include <network/http/client.hpp>
#include "rapidxml/rapidxml.hpp"

namespace network {
namespace rss {
class item {

 public:

  void set_title(const std::string& title) { title_ = title; }

  std::string title() const { return title_; }

  void set_author(const std::string& author) { author_ = author; }

  std::string author() const { return author_; }

  void set_description(const std::string& description) {
    description_ = description;
  }

  std::string description() const { return description_; }

 private:

  std::string title_;
  std::string author_;
  std::string description_;

};

class channel {

 public:
  typedef item value_type;
  typedef std::vector<item>::iterator iterator;
  typedef std::vector<item>::const_iterator const_iterator;

  channel(const http::client::response& response);
  channel(const std::shared_ptr<rapidxml::xml_document<>>& doc);

  std::string title() const { return title_; }

  std::string description() const { return description_; }

  std::string link() const { return link_; }

  std::string author() const { return author_; }

  size_t item_count() const { return items_.size(); }

  iterator begin() { return items_.begin(); }

  iterator end() { return items_.end(); }

  const_iterator begin() const { return items_.begin(); }

  const_iterator end() const { return items_.end(); }

 private:
  void parse(rapidxml::xml_document<>& doc);

  std::string title_;
  std::string description_;
  std::string link_;
  std::string author_;
  std::vector<item> items_;

};
}       // namespace rss
}       // namespace network

#endif  // ___RSS_INC__
