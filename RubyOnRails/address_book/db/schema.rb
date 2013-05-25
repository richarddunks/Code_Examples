# encoding: UTF-8
# This file is auto-generated from the current state of the database. Instead
# of editing this file, please use the migrations feature of Active Record to
# incrementally modify your database, and then regenerate this schema definition.
#
# Note that this schema.rb definition is the authoritative source for your
# database schema. If you need to create the application database on another
# system, you should be using db:schema:load, not running all the migrations
# from scratch. The latter is a flawed and unsustainable approach (the more migrations
# you'll amass, the slower it'll run and the greater likelihood for issues).
#
# It's strongly recommended to check this file into your version control system.

ActiveRecord::Schema.define(:version => 20130502180359) do

  create_table "address_types", :force => true do |t|
    t.string   "name"
    t.datetime "created_at", :null => false
    t.datetime "updated_at", :null => false
  end

  create_table "addresses", :force => true do |t|
    t.text     "street"
    t.string   "city"
    t.string   "state"
    t.integer  "zip"
    t.integer  "entry_id"
    t.integer  "address_type_id"
    t.datetime "created_at",      :null => false
    t.datetime "updated_at",      :null => false
  end

  create_table "emails", :force => true do |t|
    t.integer  "address_type_id"
    t.string   "email"
    t.datetime "created_at",      :null => false
    t.datetime "updated_at",      :null => false
    t.integer  "entry_id"
  end

  create_table "entries", :force => true do |t|
    t.string   "first_name"
    t.string   "last_name"
    t.datetime "created_at",   :null => false
    t.datetime "updated_at",   :null => false
    t.string   "title"
    t.string   "avatar"
    t.string   "avatar_cache"
  end

  create_table "urls", :force => true do |t|
    t.string   "type"
    t.string   "address"
    t.string   "address_type"
    t.datetime "created_at",   :null => false
    t.datetime "updated_at",   :null => false
  end

  create_table "webs", :force => true do |t|
    t.integer  "address_type_id"
    t.string   "web"
    t.datetime "created_at",      :null => false
    t.datetime "updated_at",      :null => false
    t.integer  "entry_id"
  end

end
