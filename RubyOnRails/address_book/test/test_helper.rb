ENV["RAILS_ENV"] = "test"

require "minitest/reporters"
MiniTest::Reporters.use! MiniTest::Reporters::SpecReporter.new

require 'simplecov' 
SimpleCov.start 'rails' do
  minimum_coverage 90
end

require File.expand_path('../../config/environment', __FILE__)
require 'rails/test_help'

class ActiveSupport::TestCase
  # Setup all fixtures in test/fixtures/*.(yml|csv) for all tests in alphabetical order.
  #
  # Note: You'll currently still have to declare fixtures explicitly in integration tests
  # -- they do not yet inherit this setting
  fixtures :all

	load "#{Rails.root}/db/seeds.rb"
end

def accessible_attrs(klass)
	klass.accessible_attributes.reject(&:blank?).reject {|a| a =~ /_attributes$/}
end
